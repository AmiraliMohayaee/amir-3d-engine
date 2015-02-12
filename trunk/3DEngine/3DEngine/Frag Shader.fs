varying vec3 pos;

// void main()
// {
	// gl_FragColor = gl_Color;

	// gl_FragColor = vec4(
		// sin(pos.x * 10), 
		// sin(pos.z * 10), 
		// 1, 
		// 1);
// }

varying vec4 diffuse;
varying vec3 normal,lightDir;

void main()
{
vec3 n = normalize(normal);
float NdotL = max(dot(n,lightDir),0.0);
vec4 color = diffuse * NdotL;
gl_FragColor = color;
}

