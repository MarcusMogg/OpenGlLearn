#version 330
out vec4 FragColor;
in vec3 ourColor;
in vec2 texPos;

uniform sampler2D texture1;

void main()
{
    FragColor = texture(texture1,texPos);
    // FragColor = vec4(ourColor.xyz, 1.0f)
} 