#version 330 core

uniform vec2 ConsolePixelUnitSize;
uniform usamplerBuffer Data; //batch data buffer.
uniform samplerBuffer Fontmap; //the coordinate uv buffer if not uv grid
uniform mat4 Matrix; //transform matrix for entire batch
out vec3 UV; //uv texture position
out vec4 FG; //foreground color
out vec4 BG; //background color
vec3 getVertexUV(int ch, int tile_vertex)
{
    int index = ch * 5;
    float s = texelFetch(Fontmap, index).r;
    index += 1;
    float t = texelFetch(Fontmap, index).r;
    index += 1;
    float p = texelFetch(Fontmap, index).r;
    index += 1;
    float q = texelFetch(Fontmap, index).r;
    index += 1;
    float page = texelFetch(Fontmap, index).r;
    vec4 uv_square = vec4(s, t, p, q);
    vec2 vert_uvs[6] = vec2[](uv_square.sp, uv_square.sq, uv_square.tq, uv_square.sp, uv_square.tq, uv_square.tp);
    vec3 uv = vec3(vert_uvs[tile_vertex], page);
    return uv;
}
vec4 getVertexPosition(int tile, int tile_vertex, inout int buffer_offset)
{
    uint x_pixel = texelFetch(Data, buffer_offset).r;
    buffer_offset += 1;
    x_pixel += texelFetch(Data, buffer_offset).r * 256u;
    buffer_offset += 1;
    uint y_pixel = texelFetch(Data, buffer_offset).r;
    buffer_offset += 1;
    y_pixel += texelFetch(Data, buffer_offset).r * 256u;
    buffer_offset += 1;
    uint tile_pixel_width = texelFetch(Data, buffer_offset).r;
    buffer_offset += 1;
    tile_pixel_width += texelFetch(Data, buffer_offset).r * 256u;
    buffer_offset += 1;
    uint tile_pixel_height = texelFetch(Data, buffer_offset).r;
    buffer_offset += 1;
    tile_pixel_height += texelFetch(Data, buffer_offset).r * 256u;
    buffer_offset += 1;
    float actual_x_pixel = float(int(x_pixel) - 16384);
    float actual_y_pixel = float(int(y_pixel) - 16384);
    float tile_screen_lx = actual_x_pixel * ConsolePixelUnitSize.x;
    float tile_screen_by = actual_y_pixel * ConsolePixelUnitSize.y;
    float tile_screen_width = float(tile_pixel_width) * ConsolePixelUnitSize.x;
    float tile_screen_height = float(tile_pixel_height) * ConsolePixelUnitSize.y;
    float tile_screen_rx = tile_screen_lx + tile_screen_width;
    float tile_screen_ty = tile_screen_by + tile_screen_height;
    vec4 position_square = vec4(tile_screen_lx, tile_screen_rx, tile_screen_ty, tile_screen_by);
    vec2 vert_positions[6] = vec2[](position_square.sp, position_square.sq, position_square.tq, position_square.sp, position_square.tq, position_square.tp);
    vec2 position = vert_positions[tile_vertex];
    return vec4(position, 0.0, 1.0) * Matrix;
}
vec4 getColor32(inout int buffer_offset)
{
    float r = float(texelFetch(Data, buffer_offset).r) / 255.0;
    buffer_offset += 1;
    float g = float(texelFetch(Data, buffer_offset).r) / 255.0;
    buffer_offset += 1;
    float b = float(texelFetch(Data, buffer_offset).r) / 255.0;
    buffer_offset += 1;
    float a = float(texelFetch(Data, buffer_offset).r) / 255.0;
    buffer_offset += 1;
    return vec4(r, g, b, a);
}
int getGlyph16(inout int buffer_offset)
{
    int glyph = int(texelFetch(Data, buffer_offset).r);
    buffer_offset += 1;
    glyph += int(texelFetch(Data, buffer_offset).r * 256u);
    buffer_offset += 1;
    return glyph;
}
void main()
{
    int tile = gl_VertexID / 6;
    int tile_vertex = gl_VertexID % 6;
    int buffer_offset = 18 * tile;
    gl_Position = getVertexPosition(tile, tile_vertex, buffer_offset);
    int glyph = getGlyph16(buffer_offset);
    UV = getVertexUV(glyph, tile_vertex);
    FG = getColor32(buffer_offset);
    BG = getColor32(buffer_offset);
}