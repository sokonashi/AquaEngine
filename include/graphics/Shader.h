#ifndef AQUAGL_SHADER_H
#define AQUAGL_SHADER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <GL/glew.h>
#include <graphics/glm/glm.hpp>
#include <graphics/glm/gtx/transform.hpp>
#include <graphics/glm/gtc/type_ptr.hpp>

enum gl_shadertype {
	VERTEX_SHADER = GL_VERTEX_SHADER,
	FRAGMENT_SHADER = GL_FRAGMENT_SHADER
};

class Shader{
private:
	std::string GetShaderSource(const std::string& ShaderPath);
	GLuint CompileShader(const std::string& SourceCode, gl_shadertype shadertype);
	void LinkShaders(GLuint shader1, GLuint shader2);

	GLuint VertShader, FragShader;
	GLuint ShaderProgram;
public:
	Shader(const std::string& VertShaderFile, const std::string& FragShaderFile);
	~Shader();

	void SetModel(const glm::mat4& Model);
	void SetView(const glm::mat4& View);
	void SetProjection(const glm::mat4& Projection);

	void SetVec3(const std::string& uniform, const glm::vec3& v);
	void SetFloat(const std::string& uniform, const float& f);
	void SetMat4(const std::string& uniform, const glm::mat4& m);

	void Bind();
	void Unbind();
};

#endif
