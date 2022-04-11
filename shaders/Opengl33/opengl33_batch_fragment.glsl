#version 330 core

uniform sampler2DArray Atlas;
in vec3 UV;
in vec4 FG;
in vec4 BG;
out vec4 FragColor;

void main()
{
    vec4 c = texture(Atlas, UV);
    c = mix(BG, FG * vec4(c.rgb, 1.0), c.a);
    FragColor = c;
}