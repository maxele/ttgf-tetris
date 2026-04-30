`default_nettype none
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
	input wire [7:0] ui_in;
	output wire [7:0] uo_out;
	input wire [7:0] uio_in;
	output wire [7:0] uio_out;
	output wire [7:0] uio_oe;
	input wire ena;
	input wire clk;
	input wire rst_n;
	reg [9:0] x_p;
	reg [9:0] x_n;
	reg [9:0] y_p;
	reg [9:0] y_n;
	reg sync_n;
	reg [1:0] r_n;
	reg [1:0] g_n;
	reg [1:0] b_n;
	reg [9:0] matrix_p [19:0];
	reg [9:0] matrix_n [19:0];
	reg [3:0] active_p [3:0];
	reg [3:0] active_n [3:0];
	reg [3:0] ax_p;
	reg [3:0] ax_n;
	reg [4:0] ay_p;
	reg [4:0] ay_n;
	reg [7:0] input_buffer_p;
	reg [7:0] input_buffer_n;
	reg [27:0] lx;
	reg [27:0] ly;
	reg [5:0] frames_n;
	reg [5:0] frames_p;
	reg [0:0] state_p;
	reg [0:0] state_n;
	always @(posedge clk or posedge rst_n)
		if (rst_n) begin
			x_p <= 0;
			y_p <= 0;
			ax_p <= 4'd3;
			ay_p <= 5'd20;
			input_buffer_p <= 0;
			frames_p <= 1;
			state_p <= 1'd1;
			begin : sv2v_autoblock_1
				integer i;
				for (i = 19; i >= 0; i = i - 1)
					begin : sv2v_autoblock_2
						integer j;
						for (j = 9; j >= 0; j = j - 1)
							matrix_p[i][j] <= 0;
					end
			end
			begin : sv2v_autoblock_3
				integer i;
				for (i = 3; i >= 0; i = i - 1)
					begin : sv2v_autoblock_4
						integer j;
						for (j = 3; j >= 0; j = j - 1)
							active_p[i][j] <= 0;
					end
			end
			matrix_p[0][0] <= 1;
			matrix_p[0][1] <= 1;
			matrix_p[0][9] <= 1;
			matrix_p[19][0] <= 1;
			matrix_p[19][9] <= 1;
			active_p[1][1] <= 1;
			active_p[1][2] <= 1;
			active_p[2][1] <= 1;
			active_p[2][2] <= 1;
		end
		else begin
			x_p <= x_n;
			y_p <= y_n;
			ax_p <= ax_n;
			ay_p <= ay_n;
			frames_p <= frames_n;
			input_buffer_p <= input_buffer_n;
			begin : sv2v_autoblock_5
				integer i;
				for (i = 19; i >= 0; i = i - 1)
					begin : sv2v_autoblock_6
						integer j;
						for (j = 9; j >= 0; j = j - 1)
							matrix_p[i][j] <= matrix_n[i][j];
					end
			end
			begin : sv2v_autoblock_7
				integer i;
				for (i = 3; i >= 0; i = i - 1)
					begin : sv2v_autoblock_8
						integer j;
						for (j = 3; j >= 0; j = j - 1)
							active_p[i][j] <= active_n[i][j];
					end
			end
			state_p <= state_n;
		end
	always @(*) begin
		if (_sv2v_0)
			;
		state_n = state_p;
		ax_n = ax_p;
		ay_n = ay_p;
		input_buffer_n = input_buffer_p | uio_in;
		case (state_p)
			1'd1: begin
				if (((x_p == 0) && (y_p == 0)) && (frames_p == 0))
					state_n = 1'd0;
				if (((input_buffer_p & 8'h01) & uio_in) > 0) begin
					ax_n = ax_p - 1;
					input_buffer_n = input_buffer_p & 8'b11111110;
				end
			end
			1'd0: begin
				ay_n = ay_p - 1;
				state_n = 1'd1;
			end
		endcase
	end
	always @(*) begin
		if (_sv2v_0)
			;
		x_n = x_p + 1;
		y_n = y_p;
		frames_n = frames_p;
		r_n = 2'b00;
		g_n = 2'b00;
		b_n = 2'b00;
		sync_n = 1;
		begin : sv2v_autoblock_9
			integer i;
			for (i = 19; i >= 0; i = i - 1)
				begin : sv2v_autoblock_10
					integer j;
					for (j = 9; j >= 0; j = j - 1)
						matrix_n[i][j] = matrix_p[i][j];
				end
		end
		begin : sv2v_autoblock_11
			integer i;
			for (i = 3; i >= 0; i = i - 1)
				begin : sv2v_autoblock_12
					integer j;
					for (j = 3; j >= 0; j = j - 1)
						active_n[i][j] = active_p[i][j];
				end
		end
		lx = 0;
		ly = 0;
		if (y_p < 10'd33)
			r_n = 1;
		else if (y_p > (10'd525 - 10'd2)) begin
			sync_n = 0;
			g_n = 1;
		end
		else if (y_p > ((10'd525 - 10'd10) - 10'd2))
			b_n = 1;
		else if (x_p < 10'd48)
			r_n = 2;
		else if (x_p > (10'd800 - 10'd96)) begin
			sync_n = 0;
			g_n = 2;
		end
		else if (x_p > ((10'd800 - 10'd16) - 10'd96))
			b_n = 2;
		else begin
			lx = ({18'b000000000000000000, x_p} - 28'h0000030) >> 4;
			ly = ({18'b000000000000000000, y_p} - 28'h0000021) >> 4;
			if (((ly == 10) && (lx > 20)) && (lx < 26)) begin
				b_n = 1;
				if (((frames_p >> (25 - lx)) & 1) == 1)
					b_n = 3;
			end
			if (((ly == 14) && (lx > 20)) && (lx < 28)) begin
				b_n = 1;
				if (((input_buffer_p >> (27 - lx)) & 1) == 1)
					b_n = 3;
			end
			if (((ly - (27 - {23'b00000000000000000000000, ay_p})) < 4) && ((lx - (10 + {23'b00000000000000000000000, ax_p})) < 4)) begin
				if (active_p[ly - (27 - {23'b00000000000000000000000, ay_p})][lx - (10 + {23'b00000000000000000000000, ax_p})])
					g_n = 2;
				else
					g_n = 1;
			end
			if (((26 - ly) < 20) && ((lx - 10) < 10)) begin
				if (matrix_p[26 - ly][lx - 10])
					r_n = 2;
				else
					r_n = 1;
			end
		end
		if (x_p >= 10'd800) begin
			y_n = y_p + 1;
			x_n = 0;
			if (y_p >= 10'd525) begin
				x_n = 0;
				y_n = 0;
				frames_n = (frames_p + 1) % 6'b000100;
			end
		end
	end
	assign uo_out = {r_n, g_n, b_n, sync_n, 1'b0};
	assign uio_out = 0;
	assign uio_oe = 0;
	wire _unused = &{uio_in, ui_in, ena};
	initial _sv2v_0 = 0;
endmodule
