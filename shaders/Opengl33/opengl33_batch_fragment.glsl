#version 330 core
uniform sampler2D Atlas;
uniform int BlendMode; /* 0 = BGR, 1 = BGG, 2 = BGB, 3 = BGA, 4 = FGR, 5 = FGG, 6 = FGB, 7 = FGA, 8 = Normal */
uniform int GlyphMode; /* G0 = 0, G8 = 1, G16 = 2 */
in vec2 UV;
in vec4 FG;
in vec4 BG;
out vec4 FragColor;
void main()
{
	if (GlyphMode == 0) //G0
	{
		FragColor = FG;
	}
	else
	{
		if (BlendMode == 0) //BGR
		{
			vec4 c = texture(Atlas, UV);
			c = mix(FG, BG * c, c.r);
			FragColor = c;
		}
		else if (BlendMode == 1) //BGG
		{
			vec4 c = texture(Atlas, UV);
			c = mix(FG, BG * c, c.g);
			FragColor = c;
		}
		else if (BlendMode == 2) //BGB
		{
			vec4 c = texture(Atlas, UV);
			c = mix(FG, BG * c, c.b);
			FragColor = c;
		}
		else if (BlendMode == 3) //BGA
		{
			vec4 c = texture(Atlas, UV);
			c = mix(BG, FG * vec4(c.rgb, 1.0), c.a);
			FragColor = c;
		}
		else if (BlendMode == 4) //FGR
		{
			vec4 c = texture(Atlas, UV);
			c = mix(BG, FG * c, c.r);
			FragColor = c;
		}
		else if (BlendMode == 5) //FGG
		{
			vec4 c = texture(Atlas, UV);
			c = mix(BG, FG * c, c.g);
			FragColor = c;
		}
		else if (BlendMode == 6) //FGB
		{
			vec4 c = texture(Atlas, UV);
			c = mix(BG, FG * c, c.b);
			FragColor = c;
		}
		else if (BlendMode == 7) //FGA
		{
			vec4 c = texture(Atlas, UV);
			c = mix(FG, BG * vec4(c.rgb, 1.0), c.a);
			FragColor = c;
		}
		else if (BlendMode == 8) //Normal
		{
			FragColor = texture(Atlas, UV);
		}
	}
}