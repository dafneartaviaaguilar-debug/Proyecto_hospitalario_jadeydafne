## Proyecto_hospitalario_jadeydafne

Proyecto de programación  
Jade Valeria Hidalgo Cascante- 209060112  
Dafne Tamara Artavia Aguilar- 209040605  
# Sistema de Gestión de Planilla Hospitalaria
Planilla Hospitalaria
Es un sistema que ayuda a administrar la planilla de un hospital. Permite registrar empleados, departamentos y puestos, calcular salarios y generar comprobantes de pago.


# Características del sistema

-Registra médicos, enfermeros y administrativos
-Administra departamentos y puestos
-Calcula salarios neto y bruto
-Calcula deducciones de ley e impuestos sobre la renta
-Registra de manera opcional la asociación solidarista
-Genera y consulta comprobantes de pago
-Almacena información mediante archivos de texto
-Usa listas enlazadas implementadas manualmente


## ---Cálculo de salarios---

# --Salario Bruto:
Salario base+horas extra+bonificacion nocturna

# --Salario neto:
Salario bruto- deducciones

El sistema contempla las siguientes deducciones:
CCSS, IVM, ROP, FCL, Asociacion Solidarista, Impuesto sobre la renta


# ---Menu Principal---
1.Registrar empleado
2.Registrar departamento
3.Registrar puesto
4.Mostrar empleados
5.Mostrar departamentos
6.Mostrar comprobantes
7.Generar comprobante
8.Guardar informacion
9.Salir

Es importante recalcar que los cambios deben guardarse mediante la opcion 8 antes de salir del programa. Se recomiendo registrar primero los departamentos para poder asignarlos a los empleados.


## ---Estructura del proyecto---
El proyecto utiliza programacion orientada a objetos e incluye:
-Herencia: Persona, empleado, medico, enfermero y administrativo
-Polimorfismo: uso de la clase abstracta Empleado
-Interfaces: ImpuestoRenta y DeduccionesSociales
-Listas enlazadas: Almacenamiento dinamico de empleados, departamentos, puestos y comprobantes
-Archivos: lectura y escritura de informacion mediante la clase Archivo


## ---Archivos de datos---
La informacion se almacena en archivos de texto:
-Archivo empleados.txt tiene la informacion de los datos de los empleados
-departamentos.txt tiene la informacion de departamentos y puestos
-asociacion.txt tiene la informacion de la afiliacion a la Asociacion Solidarista
Los archivos usan el (-) como separador, por ello se recomienda evitar este caracter en los nombres registrados.


-





