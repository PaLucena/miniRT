<h1 align="center">miniRT</h1>
MiniRT is a ray tracing project developed as part of the curriculum at Campus 42. The project aims to implement a basic ray tracer capable of rendering simple scenes with basic shapes and lighting effects.

<table align="center">
  <tr>
    <td align="center"><img src="https://github.com/PaLucena/miniRT/assets/131014763/3f0e9ab4-56e1-4f64-a3ad-121613289d70"></td>
    <td align="center"><img src="https://github.com/PaLucena/miniRT/assets/131014763/bbc99e95-88dc-4737-bc62-b1300c600ea4"></td>
  </tr>
  <tr>
    <td align="center"><img src="https://github.com/PaLucena/miniRT/assets/131014763/d8d3bee7-67bc-43c7-a5e3-90970fc93eac"></td>
    <td align="center"><img src="https://github.com/PaLucena/miniRT/assets/131014763/b35a325d-db05-4a35-9756-e9ed826516bb"></td>
  </tr>
</table>

### Features
- Ray-Sphere Intersection
- Ray-Plane Intersection
- Ray-Cylinder Intersection
- Ray-Cone Intersection
- Phong Shading Model (Ambient, Diffuse, and Specular lighting)
- Shadows
- Support for .rt files for Scene Description

### Installation
Clone the repository to your local machine:
```
git clone https://github.com/PaLucena/miniRT.git
```
Navigate to the project directory:
```
cd miniRT
```
Build the project:
```
make / make bonus
```
Usage
To run the ray tracer with a scene file:
```
  Example:

./miniRT scenes/standart.rt
```
scene.rt should be a valid scene description file in the provided format.

### Contributing
Contributions are welcome! If you'd like to contribute to miniRT, feel free to open an issue or submit a pull request with your changes.

### License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/PaLucena/miniRT/blob/master/LICENSE) file for details.
