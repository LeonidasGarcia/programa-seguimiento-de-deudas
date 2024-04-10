# programa-seguimiento-de-deudas
Proyecto final de Algorítmica I

# Estructura básica del programa

## Menu Log In
* Crear cuenta
    * Nombre completo
    * Correo electrónico
    * Numero de celular
    * DNI
    * Registrar tarjeta
        * num de tarjeta
        * CVV
        * Fecha de vencimiento
            * Confirmación por correo electrónico
    * Clave digital

* Inicio de sesión
    * Ingresar clave digital

## Menu Principal
### Mostrar saldo disponible
* Mostrar saldo disponible

### Mostrar cartera digital
* Mostrar saldo de cartera digital

### Administrar deudas
Se muestran las deudas (visualizacion simple, monto y fecha limite de pago)

### Seleccionar deuda
Se selecciona una deuda
* Pagar deuda
    * Monto a pagar 
    * Fecha limite
    * Descuento (si es con 3 dias de anticipacion)
    * Correo de confirmación

    * (Salir) o (Volver al menu)

* Visualizar deuda completa (incluye monto/mes, fecha limite de pago, intereses, monto dscto por 3 dias de anticipacion, monto supuesto ahorrado)
    * (Salir) o (Volver al menu)

### Volver al menu
* (Menu principal)

### Historial de pagos
Muestra en una tabla **las deudas canceladas y las cuotas ya pagadas de deudas sin cancelar**, dandote la opción de filtrar y mostrar boletas de pago.

### Opciones de filtro
* Filtrar por fecha
* Filtrar por monto pagado

### Boletas de pago
Puedes seleccionar la boleta de pago específica de cada importe de una deuda, imprimiendo los detalles en la pantalla y presentándote las siguientes opciones:
* Enviar una copia al correo electrónico registrado
* Imprimir la boleta de pago seleccionada


### Asesores digitales
Se muestra una lista enumerada de asesores (nombre completo, calificacion en estrellas, numero de contacto).

* opcion1: 1.¿Desea contactar un asesor?
    * Ingrese el numero de asesor para verficar su disponibilidad.
    - Si esta disponible, llamada automatica al asesor.
    - Si no esta disponible, *mensaje* y opciones(salir o volver al menu)

* opcion2: 2.Volver al menu