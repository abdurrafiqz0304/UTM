#include <iostream>
using namespace std;

#define PI 3.14
#define CUBOID 1
#define SPHERE 2

class ThreeDimensionalObject
{
private:
    double width, length, height; // attributes for cuboid
    double radius;                // attribute for sphere

public:
    double cuboidVolume() const { return width * length * height; }
    double sphereVolume() const { return (4.0 / 3.0) * PI * radius * radius * radius; }

    void inputCuboid()
    {
        cout << "Enter the dimensions, width, length and height => ";
        cin >> width >> length >> height;
    }

    void inputSphere()
    {
        cout << "Enter the radius => ";
        cin >> radius;
    }

    void displayCuboid() const
    {
        cout << "Cuboid dimensons: " << width << " x " << length << " x " << height << endl;
    }

    void displaySphere() const
    {
        cout << "Sphere's radius: " << radius << endl;
    }
};

int readUserInput()
{
    int input;
    cout << "Enter the type of object 1: Cuboid, 2: Sphere" << endl;
    cout << "=> ";
    cin >> input;
    return input;
}

int main()
{
    // Testing the class
    ThreeDimensionalObject object;
    int objectType;
    objectType = readUserInput();

    if (objectType == CUBOID)
    {
        object.inputCuboid();
        object.displayCuboid();
        cout << "Volume: " << object.cuboidVolume() << endl;
    }
    else if (objectType == SPHERE)
    {
        object.inputSphere();
        object.displaySphere();
        cout << "Volume: " << object.sphereVolume() << endl;
    }
    else{
        cout << "Invalid input" << endl;
    }

    system("pause");
    return 0;
}
