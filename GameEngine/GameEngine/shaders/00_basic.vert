
#version 410 core

// vertex position in world coordinates
// the number used for the location in the layout qualifier is the position of the vertex attribute
// as defined in the Mesh class
layout (location = 0) in vec3 position;

out vec4 vertexColor;

// with this out will be interpolated and applied by the rasterizer to all the fragment shader
void main()
{

    gl_position = vec4(position, 1.0);
    vertexColor = vec4(0.5, 0.0, 0.0, 1.0);
}
