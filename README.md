# Practica24-InputGenerator
Generador de inputs per la práctica de primavera 2024 PRO2

En el repositorio se incluye el código fuente del generador, un Makefile con los comandos necesarios para compilar el código como generar un nuevo input, y un script que se encarga de generar inputs, pasarlos entre dos programas diferentes y detectar las diferencias.

Se pueden generar inputs individualmente o hacer solo uso del script. 

Actualmente el programa está configurado para generar 100 comandos.
Este número es fácilmente customizable haciendo los respectivos cambios en src.cc.

Para el script, se adjunta un "correct.exe", un ejecutable que pasa todos los verdes de la entrega provisional. Para comparar los outputs de vuestro programa con el correcto, simplemente meted vuestro programa en el mismo directorio en el que se encuentra el script "cmp.sh" con el nombre "program.exe".
Ejecutad el script y comparará todos los outputs hasta que encuentre diferencias

(Nota: si por temas de permisos no deja ejecutar el script, ejecutad el comando "chmod +x cmp.sh")
