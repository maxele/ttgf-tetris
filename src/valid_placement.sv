// Valid Placement
// This module checks if the active piece can be transformed. To do this, the
// transformation has to be performed by this module. If the transformed
// active piece does not collide, it is valid and the active piece is updated.

module valid_placement (
	input  [19:0][9:0] field_in,
	input  [3:0][3:0] active_piece_in,
	input  signed [4:0] active_piece_x_in,
	input  signed [4:0] active_piece_y_in,

	output [3:0][3:0] active_piece_out,
	output [4:0] active_piece_x_out,
	output [4:0] active_piece_y_out,

	input [2:0]     transformation_type_in,
	output valid_out
);

	logic valid;
	logic [3:0][3:0] piece;
	logic signed [4:0] y;
	logic signed [4:0] x;

	always_comb begin
		piece = active_piece_in;
		x = active_piece_x_in;
		y = active_piece_y_in;
		valid = 0;
		case (transformation_type_in)
			INPUT_DROP: y = active_piece_y_in-1;
			INPUT_RIGHT: x = active_piece_x_in+1;
			INPUT_LEFT: x = active_piece_x_in-1;
			INPUT_ROTATE: begin
				for (int i = 0; i < 3; i++) begin
					piece[i][0] = active_piece_in[0][3-i];
					piece[0][3-i] = active_piece_in[3-i][3];
					piece[3-i][3] = active_piece_in[3][i];
					piece[3][i] = active_piece_in[i][0];
				end
				piece[1][1] = active_piece_in[1][2];
				piece[1][2] = active_piece_in[2][2];
				piece[2][2] = active_piece_in[2][1];
				piece[2][1] = active_piece_in[1][1];
			end
			default: valid = 0;
		endcase

		valid = ~|({12'b0, piece[0]} << (x+3) & {3'b111, field_in[y], 3'b111}) &
			~|({12'b0, piece[1]} << (x+3) & {3'b111, field_in[y+1], 3'b111}) &
			~|({12'b0, piece[2]} << (x+3) & {3'b111, field_in[y+2], 3'b111}) &
			~|({12'b0, piece[3]} << (x+3) & {3'b111, field_in[y+3], 3'b111});
	end

	assign active_piece_out = piece;
	assign active_piece_x_out = x;
	assign active_piece_y_out = y;
	assign valid_out = valid;

endmodule
// If the placement was valid, the active piece is updated, if not, the valid bit
// is set to low.
