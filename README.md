# Practica24-InputGenerator
Generador de inputs per la práctica de primavera 2024 PRO2

Todo comando necesario se puede hacer a través del Makefile:
  - make generate: Genera un nuevo caso de prueba
  - make clean: Limpia archivos de prueba

Actualmente el programa está configurado para generar 1000 comandos.
Este número es fácilmente customizable haciendo los respectivos cambios en src.cc.

Se adjunta un script de bash el cual se encarga de ir generando inputs aleatoriamente.
Para que este script funcione se necesita de un .exe, preferiblemente que pase todos los verdes.
Meterlo en la carpeta donde se encuentra el script con el nombre correct.exe, y vuestro programa program.exe.

Ejecutad el script y comparará todos los outputs hasta que encuentre diferencias.

(Nota: si por temas de permisos no deja ejecutar el script, ejecutad el comando "chmod +x cmp.sh")
Toda información sobre como modificar los datos se encuentra en los comentarios de src.cc
