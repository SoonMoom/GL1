#include"Renderer.h"


void GLClearError()
{
    while (glGetError() != GL_NO_ERROR)
    {

    }
}


bool GLLogCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError())
    {
        std::cout << "[OpenGL Error]:(" << error << ")" << "\n" <<
            " function is " << function << "\n" <<
            " error in " << file << "\n" <<
            " number of line is: " << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    va.Bind();
    ib.Bind();
    shader.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}


void Renderer::Clear()const
{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}