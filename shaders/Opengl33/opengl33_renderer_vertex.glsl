#version 330 core
out vec2 UV;
void main()
{
	const mat4 Matrix = mat4(2.0, 0.0, 0.0, -1.0, 0.0, -2.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	int tile_vertex = gl_VertexID % 6;
	vec4 value_square = vec4(0.0, 1.0, 1.0, 0.0);
	vec2 value_corners[6] = vec2[](value_square.sp, value_square.sq, value_square.tq, value_square.sp, value_square.tq, value_square.tp);
	UV = value_corners[tile_vertex];
	gl_Position = vec4(UV.x, 1 - UV.y, 0.0, 1.0) * Matrix;
}