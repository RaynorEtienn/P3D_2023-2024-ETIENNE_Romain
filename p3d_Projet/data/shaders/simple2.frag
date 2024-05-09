#version 330 core

in vec3 v_color;
in vec3 v_normal;
in vec3 v_position;

out vec4 out_color;

void main(void) {
    vec3 outColor = v_color;
    vec3 n = normalize(v_normal);
    
    vec3 viewDir = -normalize(v_position);
    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0));
    vec3 lightColor = vec3(1.0);
    
    vec3 ka = vec3(0.1, 0.1, 0.1);
    vec3 kd = v_color;
    vec3 ks = vec3(0.4);
    float shininess = 10.0;
    
    vec3 diffuse = kd * max(dot(n, lightDir), 0.0);
    
    vec3 r = normalize(reflect(lightDir, n));
    vec3 specular = ks * pow(max(dot(n, lightDir), 0.0), shininess);

    outColor = ka + lightColor * (diffuse + specular);
    
    out_color = vec4(outColor,1.0);
}
