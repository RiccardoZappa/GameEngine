

#version 410 core

in vec4 vertexColor;

// output variable for the fragment shader. Usually, it is the final color of the fragment
out vec4 Fragcolor;

void main()
{
    FragColor = vertexColor;
}
