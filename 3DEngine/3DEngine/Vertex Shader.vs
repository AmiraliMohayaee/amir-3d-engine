varying vec3 pos;
uniform float t;

// void main()
// {
//	gl_Position = ftransform();


	// Gourad Shading
	// vec3 normal = normalize(gl_NormalMatrix * gl_Normal);
	// vec3 lightDir = normalize(vec3(gl_LightSource[0].position));
	// float NdotL = max(dot(normal, lightDir), 0.0);
	// vec4 diffuse = gl_FrontMaterial.diffuse *
	// gl_LightSource[0].diffuse;
	// gl_FrontColor = NdotL * diffuse;
	// gl_Position = ftransform();
// }

// Phong Shading
varying vec4 diffuse;
varying vec3 normal,lightDir;

void main()
{
	normal = normalize(gl_NormalMatrix * gl_Normal);
	lightDir = normalize(vec3(gl_LightSource[0].position));
	diffuse = gl_FrontMaterial.diffuse *
	gl_LightSource[0].diffuse;
	gl_Position = ftransform();
	pos = gl_Position;
	pos += vec4(t, t, t, t);
} 