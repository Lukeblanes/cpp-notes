#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

// if we are passing vector we have to make sure to pass them by reference
void Function(const std::vector<Vertex>& vertices)
{
}
int main()
{
	// if we wouldn't use arrays we'd do something like this
	// For the stack
	Vertex vertices_stack[5];

	Vertex *vertices_heap = new Vertex[5];
	// In both cases we are tied to the size 5
	//
	// We could allocate a huge amount but we would be wasting memory
	// Vertex *vertices_heap = new Vertex[50000000];
	
	delete[] vertices_heap;


	// a good solution is the vector. We can pass any type to the vector
	std::vector<Vertex> vertices;
	// We can also choose the store Vertex* in the vector
	// It is usually more efficient to store objects rather than pointers due to the memory layout.
	// If you store objects, they are all stored in a row in memory
	// If we have to copy, then it's faster to copy pointers than objects
	//
	// passing a vector to a function. Make sure it's passed by reference
	Function(vertices);
	
	// add to vector
	vertices.push_back({ 1, 2, 3});
	vertices.push_back({ 4, 5, 6});

	// accessing the elements
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;

	// Simplified loop
	// In this example we are copying each Vertex in vertices to v.
	for (Vertex v : vertices)
		std::cout << v << std::endl;

	// To avoid copying the whole vertex we copy the reference
	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	// to remove a specific vertex. Here we delete the second element
	vertices.erase(vertices.begin() + 1);

	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	// to remove all vertices we do
	vertices.clear();

}

