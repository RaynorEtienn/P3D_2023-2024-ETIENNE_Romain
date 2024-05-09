#version 330 core

in vec3 v_color;

out vec4 out_color;

void main(void) {
    vec3 outColor = v_color;
    out_color = vec4(outColor,1.0);
}
