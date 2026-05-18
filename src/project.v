module input_buffer (
	ui_in,
	next_in,
	input_out,
	new_frame,
	clk,
	rst_n
);
	reg _sv2v_0;
	input [7:0] ui_in;
	input next_in;
	output wire [2:0] input_out;
	input new_frame;
	input clk;
	input rst_n;
	reg [23:0] keys_registers_p;
	reg [23:0] keys_registers_n;
	reg [11:0] circular_buffer_n;
	reg [11:0] circular_buffer_p;
	reg [1:0] index_start_n;
	reg [1:0] index_start_p;
	reg [1:0] index_end_n;
	reg [1:0] index_end_p;
	always @(posedge clk or posedge rst_n) begin
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
	always @(*) begin
		if (_sv2v_0)
			;
		keys_registers_n = keys_registers_p;
		circular_buffer_n = circular_buffer_p;
		index_start_n = index_start_p;
		index_end_n = index_end_p;
		if (next_in) begin
			circular_buffer_n[index_start_p * 3+:3] = 3'd0;
			index_start_n = index_start_p + 1;
		end
		begin : sv2v_autoblock_1
			reg [2:0] i;
			for (i = 0; i < 2; i = i + 1)
				begin
					if (new_frame) begin
						if (|(ui_in & (1 << i)))
							keys_registers_n[i * 6+:6] = keys_registers_p[i * 6+:6] + 1;
						else
							keys_registers_n[i * 6+:6] = 0;
					end
					if (((keys_registers_p[i * 6+:6] == 1) || (keys_registers_p[i * 6+:6] == 3)) || (keys_registers_p[i * 6+:6] == 5)) begin
						circular_buffer_n[index_end_n * 3+:3] = i + 1;
						index_end_n = index_end_p + 1;
						keys_registers_n[i * 6+:6] = 4;
					end
				end
		end
		if (|(ui_in & 4)) begin
			if (keys_registers_p[12+:6] < 1) begin
				circular_buffer_n[index_end_n * 3+:3] = 3'd3;
				index_end_n = index_end_p + 1;
				keys_registers_n[12+:6] = 2;
			end
		end
		else
			keys_registers_n[12+:6] = 0;
		if (new_frame)
			keys_registers_n[18+:6] = keys_registers_p[18+:6] + 1;
		if (keys_registers_p[18+:6] == 4) begin
			circular_buffer_n[index_end_n * 3+:3] = 3'd4;
			index_end_n = index_end_p + 1;
			keys_registers_n[18+:6] = 0;
		end
	end
	assign input_out = circular_buffer_p[index_start_p * 3+:3];
	initial _sv2v_0 = 0;
endmodule
module tt_um_maxele (
	ui_in,
	uo_out,
	uio_in,
	uio_out,
	uio_oe,
	ena,
	clk,
	rst_n
);
	reg _sv2v_0;
	input [7:0] ui_in;
	output wire [7:0] uo_out;
	input [7:0] uio_in;
	output wire [7:0] uio_out;
	output wire [7:0] uio_oe;
	input ena;
	input clk;
	input rst_n;
	reg [199:0] field_n;
	reg [199:0] field_p;
	reg [15:0] active_piece_p;
	reg [15:0] active_piece_n;
	reg signed [4:0] active_piece_x_p;
	reg signed [4:0] active_piece_x_n;
	reg signed [4:0] active_piece_y_p;
	reg signed [4:0] active_piece_y_n;
	wire [7:0] color_out;
	wire new_frame;
	reg [15:0] number_n;
	reg [15:0] number_p;
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
	wire [15:0] active_piece_trans;
	wire signed [4:0] active_piece_x_trans;
	wire signed [4:0] active_piece_y_trans;
	reg [2:0] transformation_type;
	wire transformation_valid;
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
	reg input_next_p;
	reg input_next_n;
	wire [2:0] input_to_be_processed;
	reg should_place_p;
	input_buffer inbuf(
		.ui_in(ui_in & (-1 * should_place_p)),
		.next_in(input_next_p),
		.input_out(input_to_be_processed),
		.new_frame(new_frame),
		.clk(clk),
		.rst_n(rst_n)
	);
	reg should_place_n;
	always @(posedge clk or posedge rst_n)
		if (rst_n) begin
			number_p <= 0;
			input_next_p <= 0;
			should_place_p <= 0;
			field_p <= 0;
			field_p[0] <= 1;
			field_p[22] <= 1;
			field_p[13] <= 1;
			field_p[14] <= 1;
			field_p[14] <= 1;
			field_p[56] <= 1;
			active_piece_x_p <= 1;
			active_piece_y_p <= 5;
			active_piece_p <= 0;
			active_piece_p[0] <= 1;
			active_piece_p[5] <= 1;
			active_piece_p[10] <= 1;
			active_piece_p[15] <= 1;
			active_piece_p[1] <= 1;
		end
		else begin
			active_piece_p <= active_piece_n;
			active_piece_x_p <= active_piece_x_n;
			active_piece_y_p <= active_piece_y_n;
			number_p <= number_n;
			input_next_p <= input_next_n;
			field_p <= field_n;
			should_place_p <= should_place_n;
		end
	always @(*) begin
		if (_sv2v_0)
			;
		active_piece_n = active_piece_p;
		active_piece_x_n = active_piece_x_p;
		active_piece_y_n = active_piece_y_p;
		input_next_n = 0;
		transformation_type = 3'd0;
		field_n = field_p;
		number_n = number_p;
		should_place_n = should_place_p;
		if (should_place_p) begin
			active_piece_x_n = 4;
			active_piece_y_n = 16;
			number_n = -1;
			should_place_n = 0;
		end
		else begin
			if (new_frame && (input_to_be_processed != 3'd0)) begin
				transformation_type = input_to_be_processed;
				input_next_n = 1;
			end
			if (transformation_type == 3'd4) begin
				number_n = {15'b111000000000000, !transformation_valid};
				if (!transformation_valid)
					should_place_n = 1;
			end
			if ((transformation_type != 3'd0) && transformation_valid) begin
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
	initial _sv2v_0 = 0;
endmodule
module valid_placement (
	field_in,
	active_piece_in,
	active_piece_x_in,
	active_piece_y_in,
	active_piece_out,
	active_piece_x_out,
	active_piece_y_out,
	transformation_type_in,
	valid_out
);
	reg _sv2v_0;
	input [199:0] field_in;
	input [15:0] active_piece_in;
	input signed [4:0] active_piece_x_in;
	input signed [4:0] active_piece_y_in;
	output wire [15:0] active_piece_out;
	output wire [4:0] active_piece_x_out;
	output wire [4:0] active_piece_y_out;
	input [2:0] transformation_type_in;
	output wire valid_out;
	reg valid;
	reg [15:0] piece;
	reg signed [4:0] y;
	reg signed [4:0] x;
	always @(*) begin
		if (_sv2v_0)
			;
		piece = active_piece_in;
		x = active_piece_x_in;
		y = active_piece_y_in;
		valid = 0;
		case (transformation_type_in)
			3'd4: y = active_piece_y_in - 1;
			3'd2: x = active_piece_x_in + 1;
			3'd1: x = active_piece_x_in - 1;
			3'd3: begin
				begin : sv2v_autoblock_1
					reg signed [31:0] i;
					for (i = 0; i < 3; i = i + 1)
						begin
							piece[i * 4] = active_piece_in[0 + (3 - i)];
							piece[0 + (3 - i)] = active_piece_in[((3 - i) * 4) + 3];
							piece[((3 - i) * 4) + 3] = active_piece_in[12 + i];
							piece[12 + i] = active_piece_in[i * 4];
						end
				end
				piece[5] = active_piece_in[6];
				piece[6] = active_piece_in[10];
				piece[10] = active_piece_in[9];
				piece[9] = active_piece_in[5];
			end
			default: valid = 0;
		endcase
		valid = ((~|(({12'b000000000000, piece[0+:4]} << (x + 3)) & {3'b111, field_in[y * 10+:10], 3'b111}) & ~|(({12'b000000000000, piece[4+:4]} << (x + 3)) & {3'b111, field_in[(y + 1) * 10+:10], 3'b111})) & ~|(({12'b000000000000, piece[8+:4]} << (x + 3)) & {3'b111, field_in[(y + 2) * 10+:10], 3'b111})) & ~|(({12'b000000000000, piece[12+:4]} << (x + 3)) & {3'b111, field_in[(y + 3) * 10+:10], 3'b111});
	end
	assign active_piece_out = piece;
	assign active_piece_x_out = x;
	assign active_piece_y_out = y;
	assign valid_out = valid;
	initial _sv2v_0 = 0;
endmodule
module vga_graphics (
	field_in,
	active_piece_in,
	active_piece_x_in,
	active_piece_y_in,
	number_in,
	color_out,
	new_frame_out,
	clk,
	rst_n
);
	reg _sv2v_0;
	input [199:0] field_in;
	input [15:0] active_piece_in;
	input signed [4:0] active_piece_x_in;
	input signed [4:0] active_piece_y_in;
	input [15:0] number_in;
	output wire [7:0] color_out;
	output wire new_frame_out;
	input clk;
	input rst_n;
	reg new_frame_n;
	reg [1:0] r_n;
	reg [1:0] g_n;
	reg [1:0] b_n;
	reg vsync_n;
	reg hsync_n;
	reg [9:0] x_p;
	reg [9:0] x_n;
	reg [9:0] y_p;
	reg [9:0] y_n;
	reg signed [5:0] lx;
	reg signed [5:0] ly;
	wire signed [9:0] lxtmp;
	wire signed [9:0] lytmp;
	always @(posedge clk or posedge rst_n) begin
		if (rst_n) begin
			x_p <= 0;
			y_p <= 0;
		end
		x_p <= x_n;
		y_p <= y_n;
	end
	always @(*) begin
		if (_sv2v_0)
			;
		lx = 0;
		ly = 0;
		r_n = 0;
		g_n = 0;
		b_n = 0;
		hsync_n = 0;
		vsync_n = 0;
		new_frame_n = 0;
		x_n = x_p + 1;
		y_n = y_p;
		if (x_p >= 10'd800) begin
			y_n = y_p + 1;
			x_n = 0;
			if (y_p >= 10'd525) begin
				x_n = 0;
				y_n = 0;
				new_frame_n = 1;
			end
		end
		if (y_p < 10'd33)
			r_n = 1;
		else if (y_p > (10'd525 - 10'd2)) begin
			vsync_n = 1;
			g_n = 1;
		end
		else if (y_p > ((10'd525 - 10'd10) - 10'd2))
			b_n = 1;
		else if (x_p < 10'd48)
			r_n = 2;
		else if (x_p > (10'd800 - 10'd96)) begin
			hsync_n = 1;
			g_n = 2;
		end
		else if (x_p > ((10'd800 - 10'd16) - 10'd96))
			b_n = 2;
		else begin
			lx = x_p[9:4] - (10'd48 >> 3);
			ly = (((10'd525 - 10'd10) - 10'd2) >> 3) - y_p[9:4];
			if (((lx == 28) && (ly >= 8)) && (ly < 24)) begin
				g_n = 1;
				if (number_in[ly - 8])
					g_n = 3;
			end
			if ((((lx >= 12) && (lx < 22)) && (ly >= 5)) && (ly < 25)) begin
				g_n = 1;
				if (field_in[((ly - 5) * 10) + (lx - 12)])
					g_n = 3;
			end
			if ((((lx >= (12 + active_piece_x_in)) && (lx < (16 + active_piece_x_in))) && (ly >= (5 + active_piece_y_in))) && (ly < (9 + active_piece_y_in))) begin
				b_n = 1;
				if (active_piece_in[(((ly - 5) - active_piece_y_in) * 4) + ((lx - 12) - active_piece_x_in)] > 0)
					b_n = 3;
			end
		end
	end
	assign new_frame_out = new_frame_n;
	assign color_out = {r_n, g_n, b_n, vsync_n, hsync_n};
	assign color_out = {r_n[1], g_n[1], b_n[1], vsync_n, r_n[0], g_n[0], b_n[0], hsync_n};
	initial _sv2v_0 = 0;
endmodule
