#include <iostream>
#include <string>
using namespace std;

struct producto {
    int id;
    string nombre;
    float precio;
    int cantidad;
};

int main() {
    int opcion = 0;
    producto inventario[200];
    int totalProductos = 0;
    float totalVentas = 0.0;
    string historialCompras[200];
    int totalCompras = 0;

    do {
        
        cout << "\nMenú de opciones\n";
        cout << "1. Agregar producto\n";
        cout << "2. Realizar compra\n";
        cout << "3. Mostrar inventario\n";
        cout << "4. Buscar producto por nombre\n";
        cout << "5. Generar reporte de ventas\n";
        cout << "6. Actualizar el precio de un producto\n";
        cout << "7. Ver historial de compras\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (totalProductos < 200) {
                   
                    cout << "Ingrese el nombre del producto: ";
                    cin >> inventario[totalProductos].nombre;
                    cout << "Ingrese el precio del producto: ";
                    cin >> inventario[totalProductos].precio;
                    cout << "Ingrese la cantidad del producto: ";
                    cin >> inventario[totalProductos].cantidad;
                    totalProductos++;
                } else {
                    cout << "Inventario lleno. No se pueden agregar más productos." << endl;
                }
                break;

            case 2:
                if (totalProductos == 0) {
                    cout << "No hay productos disponibles en el inventario." << endl;
                    break;
                }

                
                cout << "¿Qué producto desea comprar?" << endl;
                cout << "Tenemos los siguientes productos:" << endl;
                for (int i = 0; i < totalProductos; i++) {
                    cout << i + 1 << ". " << inventario[i].nombre
                         << " - Precio: " << inventario[i].precio
                         << " - Cantidad disponible: " << inventario[i].cantidad << endl;
                }

                int productoSeleccionado;
                cout << "Ingrese el número del producto: ";
                cin >> productoSeleccionado;

                if (productoSeleccionado < 1 || productoSeleccionado > totalProductos) {
                    cout << "Producto inválido. Intente nuevamente." << endl;
                    break;
                }

                productoSeleccionado--; 
                int cantidadCompra;
                cout << "Ingrese la cantidad que desea comprar: ";
                cin >> cantidadCompra;

                if (cantidadCompra > inventario[productoSeleccionado].cantidad) {
                    cout << "Inventario insuficiente. Solo hay "
                         << inventario[productoSeleccionado].cantidad
                         << " unidades disponibles." << endl;
                    break;
                }

                float totalAPagar = cantidadCompra * inventario[productoSeleccionado].precio;
                cout << "El total a pagar es: $" << totalAPagar << endl;

                float pago;
                cout << "Ingrese el monto con el que va a pagar: ";
                cin >> pago;

                if (pago < totalAPagar) {
                    cout << "El monto ingresado es insuficiente. Compra cancelada." << endl;
                    break;
                }

                float vuelto = pago - totalAPagar;
                cout << "Compra realizada con éxito. Su vuelto es: $" << vuelto << endl;

                inventario[productoSeleccionado].cantidad -= cantidadCompra;

                
                historialCompras[totalCompras] = "Producto: " + inventario[productoSeleccionado].nombre +
                                                 ", Cantidad: " + to_string(cantidadCompra) +
                                                 ", Total: $" + to_string(totalAPagar);
                totalCompras++;

                
                totalVentas += totalAPagar;
                break;

            case 3:
                if (totalProductos == 0) {
                    cout << "El inventario está vacío." << endl;
                } else {
                    
                    cout << "Inventario actual:" << endl;
                    for (int i = 0; i < totalProductos; i++) {
                        cout << i + 1 << ". " << inventario[i].nombre
                             << " - Precio: " << inventario[i].precio
                             << " - Cantidad: " << inventario[i].cantidad << endl;
                    }
                }
                break;

            case 4:{
           
              string nombreBusqueda;
                cout << "Ingrese el nombre del producto que desea buscar: ";
                cin >> nombreBusqueda;
        
                bool encontrado = false; 
        
                for (int i = 0; i < totalProductos; i++) {
                    if (inventario[i].nombre == nombreBusqueda) {
                        cout << "Producto encontrado:" << endl;
                        cout << "Nombre: " << inventario[i].nombre << endl;
                        cout << "Precio: $" << inventario[i].precio << endl;
                        cout << "Cantidad disponible: " << inventario[i].cantidad << endl;
                        encontrado = true;
                        break; 
                    }
                }
        
                if (!encontrado) {
                    cout << "Producto no encontrado en el inventario." << endl;
                }
            }
            break;
        

            case 5:
    
             cout << "\nReporte de Ventas\n";
             cout << "Total de ventas: $" << totalVentas << endl;

 
             if (totalProductos == 0) {
             cout << "No hay productos en el inventario." << endl;
             }   else {
              cout << "\nVentas por producto:\n";
              for (int i = 0; i < totalProductos; i++) {
                int cantidadVendida= inventario[i].cantidad ;
             
             if (cantidadVendida < inventario[i].cantidad) {
                int cantidadVendidaReal = inventario[i].cantidad - cantidadVendida;
                float ventasPorProducto = cantidadVendidaReal * inventario[i].precio;
                cout << "Producto: " << inventario[i].nombre
                     << " | Cantidad Vendida: " << cantidadVendidaReal
                     << " | Total generado: $" << ventasPorProducto << endl;
            }
        }
    }

    break;

                
               

            case 6:

            //cambio de precio
                
               

            case 7:
              
                if (totalCompras == 0) {
                    cout << "No hay compras registradas." << endl;
                } else {
                    cout << "Historial de compras:" << endl;
                    for (int i = 0; i < totalCompras; i++) {
                        cout << historialCompras[i] << endl;
                    }
                }
                break;

            case 8:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }

    } while (opcion != 8);

    return 0;
}
