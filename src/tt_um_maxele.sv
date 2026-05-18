// Small Tetris
// authored by Max Masiero
//
// Sources:
// https://tinytapeout.com/
// https://projectf.io/posts/video-timings-vga-720p-1080p/#640x480-60-hz

// These definitions dictate how fast the game should be. They are so
// small beacuse my testing framework is so slow.
`define LINE_BREAK_DELAY 3      // 1 frame
`define DEBUG_NUMBER_SIZE 16

module tt_um_maxele (
	input  [7:0] ui_in,   // Dedicated inputs
	output [7:0] uo_out,  // Dedicated outputs
	input  [7:0] uio_in,  // IOs: Input path
	output [7:0] uio_out, // IOs: Output path
	output [7:0] uio_oe,  // IOs: Enable path (active high: 0=input, 1=output)
	input  ena,           // always 1 when the design is powered, so you can ignore it
	input  clk,           // clock
	input  rst_n          // reset_n - low to reset
);

	logic [19:0][9:0] field_n, field_p; // Game Logic
	logic [3:0][3:0] active_piece_p, active_piece_n;      // Valid Placement
	logic signed [4:0] active_piece_x_p, active_piece_x_n;  // Valid Placement
	logic signed [4:0] active_piece_y_p, active_piece_y_n;  // Valid Placement

	logic [7:0] color_out;              // VGA Graphics
	logic new_frame;                    // VGA Graphics
	logic [`DEBUG_NUMBER_SIZE-1:0] number_n, number_p;

	vga_graphics vga(
		.field_in(field_n),
		.active_piece_in(active_piece_p),
		.active_piece_x_in(active_piece_x_p),
		.active_piece_y_in(active_piece_y_p),
		.number_in(number_p),
		.color_out(color_out),
		.new_frame_out(new_frame),
		.clk(clk),
		.rst_n(rst_n)
	);

	logic [3:0][3:0] active_piece_trans;     // Valid Placement
	logic signed [4:0] active_piece_x_trans; // Valid Placement
	logic signed [4:0] active_piece_y_trans; // Valid Placement
	logic [2:0] transformation_type;
	logic transformation_valid;

	valid_placement place(
		.field_in(field_p),
		.active_piece_in(active_piece_p),
		.active_piece_x_in(active_piece_x_p),
		.active_piece_y_in(active_piece_y_p),
		.active_piece_out(active_piece_trans),
		.active_piece_x_out(active_piece_x_trans),
		.active_piece_y_out(active_piece_y_trans),
		.transformation_type_in(transformation_type),
		.valid_out(transformation_valid)
	);

	logic input_next_p, input_next_n;
	logic [2:0] input_to_be_processed;

	input_buffer inbuf(
		.ui_in(ui_in& (-1 * should_place_p)),
		.next_in(input_next_p),
		.input_out(input_to_be_processed),
		.new_frame(new_frame),
		.clk(clk),
		.rst_n(rst_n)
	);

	logic should_place_p, should_place_n;

	always_ff @(posedge clk or posedge rst_n) begin
		if (rst_n) begin
			number_p <= 0;
			input_next_p <= 0;
			should_place_p <= 0;

			field_p <= 0;
			field_p[0][0] <= 1;
			field_p[2][2] <= 1;
			field_p[1][3] <= 1;
			field_p[1][4] <= 1;
			field_p[1][4] <= 1;
			field_p[5][6] <= 1;

			active_piece_x_p <= 1;
			active_piece_y_p <= 5;
			active_piece_p <= 0;
			active_piece_p[0][0] <= 1;
			active_piece_p[1][1] <= 1;
			active_piece_p[2][2] <= 1;
			active_piece_p[3][3] <= 1;

			active_piece_p[0][1] <= 1;
		end else begin
			active_piece_p <= active_piece_n;
			active_piece_x_p <= active_piece_x_n;
			active_piece_y_p <= active_piece_y_n;
			number_p <= number_n;
			input_next_p <= input_next_n;
			field_p <= field_n;
			should_place_p <= should_place_n;
		end
	end

	always_comb begin
		active_piece_n = active_piece_p;
		active_piece_x_n = active_piece_x_p;
		active_piece_y_n = active_piece_y_p;
		input_next_n = 0;
		transformation_type = INPUT_NONE;
		field_n = field_p;
		number_n = number_p;
		should_place_n = should_place_p;

		if (should_place_p) begin
			active_piece_x_n = 4;
			active_piece_y_n = 16;
			number_n = -1;
			should_place_n = 0;
		end else begin
			if (new_frame && input_to_be_processed != INPUT_NONE) begin
				transformation_type = input_to_be_processed;
				input_next_n = 1;
			end

			if (transformation_type == INPUT_DROP) begin
				number_n = {3'b111, 12'b0, !transformation_valid};
				if (!transformation_valid) should_place_n = 1;
			end

			if (transformation_type != INPUT_NONE && transformation_valid) begin
				active_piece_n = active_piece_trans;
				active_piece_x_n = active_piece_x_trans;
				active_piece_y_n = active_piece_y_trans;
			end
		end
	end

	assign uo_out = color_out;
	assign uio_out = 0;
	assign uio_oe = 0;
	wire _unused = &{ena, uio_in, ui_in};
endmodule
