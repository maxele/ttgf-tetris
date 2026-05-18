// VGA Graphics
// This module is responsible for showing things on a VGA compatible monitor
// using the [640x480p60][2] VGA standard.

`define HORIZONTAL_TOTAL         10'd800
`define VERTICAL_TOTAL           10'd525

`define HORIZONTAL_FRONT_PORCH   10'd16
`define HORIZONTAL_BACK_PORCH    10'd48
`define HORIZONTAL_SYNC          10'd96

`define VERTICAL_FRONT_PORCH     10'd10
`define VERTICAL_BACK_PORCH      10'd33
`define VERTICAL_SYNC            10'd2

`define VERTICAL_VISIBLE         `VERTICAL_TOTAL-\
	`VERTICAL_FRONT_PORCH-`VERTICAL_SYNC

module vga_graphics (
	input  [19:0][9:0] field_in,
	input  [3:0][3:0] active_piece_in,
	input  signed [4:0] active_piece_x_in,
	input  signed [4:0] active_piece_y_in,
	input  [`DEBUG_NUMBER_SIZE-1:0] number_in,
	output [7:0] color_out,
	output new_frame_out,
	input  clk,
	input  rst_n
);
	logic new_frame_n;
	logic [1:0] r_n;
	logic [1:0] g_n;
	logic [1:0] b_n;
	logic sync_n;

	logic [9:0] x_p, x_n;
	logic [9:0] y_p, y_n;

	logic signed [5:0] lx;
	logic signed [5:0] ly;
	logic signed [9:0] lxtmp;
	logic signed [9:0] lytmp;

	always_ff @(posedge clk or posedge rst_n) begin
		if (rst_n) begin
			x_p <= 0;
			y_p <= 0;
		end
		x_p <= x_n;
		y_p <= y_n;
	end


	always_comb begin
		lx = 0; ly = 0;
		r_n = 0; g_n = 0; b_n = 0; sync_n = 0;
		new_frame_n = 0;

		x_n = x_p+1;
		y_n = y_p;
		if (x_p >= `HORIZONTAL_TOTAL) begin
			y_n = y_p + 1;
			x_n = 0;
			if (y_p >= `VERTICAL_TOTAL) begin
				x_n = 0;
				y_n = 0;
				new_frame_n = 1;
			end
		end

		if (y_p < `VERTICAL_BACK_PORCH) begin
			r_n = 1;
		end else if (y_p > `VERTICAL_TOTAL-`VERTICAL_SYNC) begin
			sync_n = 0;
			g_n = 1;
		end else if (y_p > `VERTICAL_TOTAL-`VERTICAL_FRONT_PORCH-`VERTICAL_SYNC) begin
			b_n = 1;
		end else if (x_p < `HORIZONTAL_BACK_PORCH) begin
			r_n = 2;
		end else if (x_p > `HORIZONTAL_TOTAL-`HORIZONTAL_SYNC) begin
			sync_n = 0;
			g_n = 2;
		end else if (x_p > `HORIZONTAL_TOTAL-`HORIZONTAL_FRONT_PORCH-`HORIZONTAL_SYNC) begin
			b_n = 2;
		end else begin
			// If in the actually visible space
			// local variables relative to the pixelated version
			// of the visible space
			lx = x_p[9:4] - (`HORIZONTAL_BACK_PORCH >> 3);
			ly = (`VERTICAL_VISIBLE >> 3) - y_p[9:4];

			if (lx == 28 && ly >= 8 && ly < 8+`DEBUG_NUMBER_SIZE) begin
				g_n = 1;
				if (number_in[ly-8])
					g_n = 3;
			end

			if (lx >= 12 && lx < 22 && ly >= 5 && ly < 25) begin
				g_n = 1;
				if (field_in[ly-5][lx-12]) begin
					g_n = 3;
				end
			end

			if (lx >= 12 + active_piece_x_in && lx < 16 + active_piece_x_in &&
				ly >= 5 + active_piece_y_in && ly < 9 + active_piece_y_in) begin
				b_n = 1;
				if (active_piece_in[ly-5-active_piece_y_in][lx-12-active_piece_x_in] > 0) begin
					b_n = 3;
				end
			end
		end
	end

	assign new_frame_out = new_frame_n;
	assign color_out = {r_n, g_n, b_n, sync_n, 1'h0};
endmodule
