#version 330 core

out vec4 FragColor;

in vec2 iTexCoord;

uniform sampler2D uTexture;

void main()
{
    FragColor = texture(uTexture, iTexCoord) * vec4(0.1, 0.0, 0.0, 1.0);
}