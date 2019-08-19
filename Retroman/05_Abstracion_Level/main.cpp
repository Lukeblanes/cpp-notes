// notes from https://www.youtube.com/watch?v=7ybD2oC3PWY
#include <iostream>
#include <math.h>

// NON_COMPILABLE EXAMPLE

/*    INITIAL VERSION
void Waypoints::createWeights() {
    float weightX = 0.0f;
    float weightZ = 0.0f;
    float weight  = 0.0f;
 
    pesos = new float*[puntos.size()];
    for (int i=0; i < puntos.size(); i++) {
        pesos[i] = new float[puntos.size()];
    }
    for (int i=0; i < puntos.size(); i++) {
        for (int j=0; j < puntos.size(); j++) {
            pesos[i][j] = 0;
            if (puntos[i].name != puntos[j].name) {
                weightX = pow((puntos[j].pos.X-puntos[i].pos.X), 2);
                weightZ = pow((puntos[j].pos.Z-puntos[i].pos.Z), 2);
                weight = weightX + weightZ;
                weight = sqrt(weight);
                pesos[i][j] = weight;
            }
        }
    }
}
*/

// Level abstraction is something to have in mind while programming
// It makes code easier to understand, mantain and extend.

// when going up in abstraction, it's what we are doing
// when goind down, it's how we are doing it

// mixing the what and how makes our code worse.

// The calculations in the loop should probably be at a lower level
// so we move it to it's own function

float calculateDistance(const Point& Orig, const Point& Dest)
{
    float weightX = pow((Dest.pos.X - Orig.pos.X), 2);
    float weightZ = pow((Dest.pos.Z - Orig.pos.Z), 2);
    float weight = sqrt(weightX + weightZ);
    return weight;
}

// The Initialization of the matrix is also something that shouldn't be done
// in createWeights

// in the original code we didn't do certain memory management operations
// so we should do that

/*  // 
void initializeMatrix()
{
    float weightX = 0.0f;
    float weightZ = 0.0f;
    float weight  = 0.0f;
 
    pesos = new float*[puntos.size()];
    for (int i=0; i < puntos.size(); i++) {
        pesos[i] = new float[puntos.size()];
    }

}
*/

void freeMatrixMemoryIfExists()
{
    if(pesos)
    {
        for (std::size_t i = 0; i < puntos.size(); i++)
        {
            delete[] pesos[i];
            pesos[i] = nullptr;
        }
        delete[] pesos;
        pesos = nullptr;
    }
}

void reserveMemoryMatrix()
{
    pesos = new float*[puntos.size()];
    for (int i = 0; i < puntos.size(); i++)
    {
        pesos[i] = new float[puntos.size()];
    }
}

// This improves legibility
void initializeMatrix()
{
    freeMatrixMemoryIfExists();
    reserveMemoryMatrix();
}

// There's also an improvement on the implementation side of things
// Calculating distance from puntos[i] and puntos[j] if the values are 1 and 3,
// we will obtain the same result as doing 3 and 1
// we solve this by initializing j to i+1 so we never repeat what we check

// another detail is using int for the iterator in the for loop
// puntos.size() return size_t so if we use int, it will generate warnings.
// it's better to use 

void createWeights() 
{
    initializeMatrix();
    
    for (std::size_t i=0; i < puntos.size(); i++) 
    {
        for (std::size_t j=i+1; j < puntos.size(); j++) 
        {
                pesos[i][j] = calculateDistance(puntos[i], puntos[j]);
                pesos[j][i] = pesos[i][j];
        }
    }
}
