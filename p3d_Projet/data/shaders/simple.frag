#version 330 core

uniform vec3 color_vector;    // On met des entrées uniformes afin qu'elles soient communes à tous les sommets d'un atome
uniform float radius;
uniform vec3 center_vector;
uniform mat4 view_matrix;
uniform mat4 model_matrix;
uniform mat4 projection_matrix;

in vec3 v_normal;
in vec3 v_position;

out vec4 out_color;

void main(void) {
   vec4 new_center= view_matrix*model_matrix*vec4(0.f,0.f,0.f,1.f); // On definit le nouveau centre
   
   vec3 v=new_center.xyz;
   
   vec3 viewDir = -normalize(v_position);
   
   float a=dot(viewDir,viewDir);
   float b=-2*dot(viewDir,v);
   
   float c=dot(v,v) - radius*radius;
   float alpha=1.f;
   float delta = b*b - 4*a*c; // Calcul du discriminant, dans le but de trouver le facteur alpha qui nous donnera accès à la position "sur la sphère", et à la vraie normale.

   if (delta < 0)
   {
   	discard;
   }
      
   float alpha1 = (-b+sqrt(delta))/(2*a);
   float alpha2 = (-b-sqrt(delta))/(2*a);
   if(dot(v_position-alpha1*v_position,v_position-alpha1*v_position)> dot(v_position-alpha2*v_position,v_position-alpha2*v_position))
   {
   	alpha = alpha2;
   }
   else 
   {
   	alpha = alpha1;
   } 
    
    
    
    vec3 outColor = color_vector;
    vec3 P_p = alpha*viewDir;
    vec3 n = P_p - v;
    n= normalize(n);
    
    

    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0));
    vec3 lightColor = vec3(1.0);
    
    vec3 ka = vec3(0.1, 0.1, 0.1);
    vec3 kd = color_vector;
    vec3 ks = vec3(0.4);
    float shininess = 10.0;
    
    vec3 diffuse = kd * max(dot(n, lightDir), 0.0);
    
    vec3 r = normalize(reflect(lightDir, n));
    vec3 specular = ks * pow(max(dot(n, lightDir), 0.0), shininess);

    outColor = ka + lightColor * (diffuse + specular);
    
    out_color = vec4(outColor,1.0);
    
    // Soigne la fusion des atomes, en ajustant la profondeur
    vec4 P_projected = projection_matrix*vec4(P_p,1.0);
    float ndcDepth = P_projected.z/P_projected.w;
    gl_FragDepth = ((gl_DepthRange.diff * ndcDepth)+ gl_DepthRange.near + gl_DepthRange.far) / 2.0;
     
    }
