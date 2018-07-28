#version 120

varying vec2 texCoord0;
varying vec3 normal0;

uniform sampler2D sampler;
uniform vec3 lightDirection;

void main() {
	gl_FragColor = texture2D(sampler, texCoord0) * clamp(dot(-lightDirection, normal0), 0.0, 1.0) * vec4(0.53, 0.59, 0.43, 1);
	/* gl_FragColor = vec4(0.53, 0.59, 0.43, 1); */
}
