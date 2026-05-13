// Input Buffer
// This module implements a delay between a keypress and its action, also it
// implements a second delay, different than the first, for when a key is
// pressed down even longer and should repeat automatically.

`define KEY_LEFT   1
`define KEY_RIGHT  2
`define KEY_ROTATE 3

`define FIRST_KEYPRESS_DELAY 3  // 2 frames
`define SECOND_KEYPRESS_DELAY 1 // 1 frame
`define DROP_DELAY 32 // 1 frame

typedef enum logic [2:0] {
	INPUT_NONE,
	INPUT_LEFT,
	INPUT_RIGHT,
	INPUT_ROTATE,
	INPUT_DROP
} input_t;

module input_buffer (
	input  [7:0] ui_in,
	input        next_in,
	output [2:0] input_out,
	input        new_frame,
	input        clk,
	input        rst_n
);

	logic [3:0][5:0] keys_registers_p;
	logic [3:0][5:0] keys_registers_n;

	// Worst case multiple buttons are pressed at the same time, so 4
	logic [3:0][2:0] circular_buffer_n, circular_buffer_p;
	logic [1:0] index_start_n, index_start_p;
	logic [1:0] index_end_n, index_end_p;

	always_ff @(posedge clk or posedge rst_n) begin
		if (rst_n) begin
			keys_registers_p <= 0;
			circular_buffer_p <= 0;
			index_start_p <= 0;
			index_end_p <= 0;
		end
		keys_registers_p <= keys_registers_n;
		circular_buffer_p <= circular_buffer_n;
		index_start_p <= index_start_n;
		index_end_p <= index_end_n;
	end

	always_comb begin
		keys_registers_n = keys_registers_p;
		circular_buffer_n = circular_buffer_p;
		index_start_n = index_start_p;
		index_end_n = index_end_p;

		// detect next_in and advance the indices
		if (next_in) begin
			// remove input from circular buffer
			circular_buffer_n[index_start_p] = INPUT_NONE;
			index_start_n = index_start_p + 1;
		end

		// increase all registers
		for (logic [2:0] i = 0; i < 2; i++) begin
			if (new_frame) begin
				if (|(ui_in & (1<<i)))
					keys_registers_n[i] = keys_registers_p[i] + 1;
				else 
					keys_registers_n[i] = 0;
			end
			if (keys_registers_p[i] == `FIRST_KEYPRESS_DELAY
				|| keys_registers_p[i] == `FIRST_KEYPRESS_DELAY+1+`SECOND_KEYPRESS_DELAY) begin
				// add input to circular buffer
				circular_buffer_n[index_end_n] = i+1;
				index_end_n = index_end_p + 1;
				keys_registers_n[i] = `FIRST_KEYPRESS_DELAY+1;
			end
		end

		// for rotate
		if (|(ui_in & (1 << 2))) begin
			if (keys_registers_p[2] < 1) begin
				// add input to circular buffer
				circular_buffer_n[index_end_n] = INPUT_ROTATE;
				index_end_n = index_end_p + 1;
				keys_registers_n[2] = 2;
			end
		end else begin
			keys_registers_n[2] = 0;
		end

		// // for automatic drop
		// keys_registers_n[3] = keys_registers_p[3] + 1;
		// if (keys_registers_p[3] == 15) begin
		// // 	// add input to circular buffer
		// 	circular_buffer_n[index_end_n] = INPUT_DROP;
		// 	index_end_n = index_end_p + 1;
		// 	keys_registers_n[3] = 0;
		// end
	end

	assign input_out = circular_buffer_p[index_start_p];
endmodule
