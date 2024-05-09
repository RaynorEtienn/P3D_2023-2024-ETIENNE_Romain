#version 330 core

uniform mat4 model_matrix;
uniform mat4 projection_matrix;

in vec3 vtx_position;
in vec3 vtx_color;

out vec3 v_color;
out vec3 v_normal;

void main()
{
    v_color = vtx_color;
    gl_Position = projection_matrix * model_matrix * vec4(vtx_position, 1.0);
}
