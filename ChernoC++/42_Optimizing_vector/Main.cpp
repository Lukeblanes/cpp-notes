#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}
	
	// To start optimizing we need to know when the vector copies Vertex so we are going to create a copy constructor
	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "COPY VERTEX!" << std::endl;
	}
};

int main()
{
	std::cout << "No Optimization" << std::endl;
	// There are six copies being done in the snippet below
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(1, 2, 3));
	// After adding the first element, we only copy one element to the new allocated array
	vertices.push_back(Vertex(4, 5, 6));
	// After pushing back the second element we get two copies, we allocate new arrayelement, copy first element, and copy second element
	vertices.push_back(Vertex(7, 8, 9));
	// This copies 3 vertices
	//
	// One of things we can do is to see if we can avoid copying an object when adding a new Vertex
	// The other is if we know that our vector is going to be a specific size, we should be able to set so it doesn't do as many resizes
	
	std::cout << "Optimized vertices copies with reserve" << std::endl;
	std::vector<Vertex> optim_res_vertices;
	optim_res_vertices.reserve(3); // Initial array size is now 3
	optim_res_vertices.push_back(Vertex(1, 2, 3));
	optim_res_vertices.push_back(Vertex(4, 5, 6));
	optim_res_vertices.push_back(Vertex(7, 8, 9));
	// After Doing the reserve, we only do 3 copies.
	
	// The next optimization we would want is to actually construct the vertex inside the vector so that we don't have to copy it
	// We do that with emplace_back. Emplace back passes the parameters for the constructor of the object
	// It basically says to construct a vector with the following parameters
	
	std::cout << "Optimized vertices copies with emplace_back and reserve" << std::endl;
	std::vector<Vertex> optim_vertices;
	optim_vertices.reserve(3); // Initial array size is now 3
	optim_vertices.emplace_back(1, 2, 3);
	optim_vertices.emplace_back(4, 5, 6);
	optim_vertices.emplace_back(7, 8, 9);
	// After using emplace_back we don't use the copy constructor of Vertex anymore
}

