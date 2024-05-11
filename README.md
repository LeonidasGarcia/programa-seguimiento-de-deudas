# Estructura de ***Deuda Cero***
Estructura de nuestro proyecto final de Algorítmica I. 

---

<center><strong style="color: red">¡Sometido a cambios!</strong></center>

***Aclaración: TODOS los menús/submenús cuentan con la opción de salir del menú/submenú actual y volver al menú/submenú. anterior.***

---

### Tabla de contenidos

1. [Menú Login](#menu-login)
    * [Crear una cuenta](#crear-una-cuenta)
    * [Iniciar sesión](#inicio-de-sesión)
2. [Menú principal](#menu-principal)
    * [Mostrar saldo](#mostrar-saldo)
    * [Mostrar cartera digital](#mostrar-cartera-digital)
    * [Administrar deudas](#administrar-deudas)
    * [Historial de pagos](#historial-de-pagos)
    * [Nuestros asesores digitales](#asesores-digitales)

## Menu Login
Es lo primero que se muestra al iniciar el programa, dispone únicamente de 2 opciones principales [crear una cuenta](#crear-una-cuenta) e [iniciar sesion](#inicio-de-sesión). En el código, esta asociado a la tabla de usuarios de la base de datos de .csv del proyecto.

### Crear una cuenta

---

La creación de una cuenta para nuestro programa requiere de los siguientes datos:
1. ***Nombre completo***
2. ***Correo electrónico***
3. ***Numero de celular***
4. ***DNI***

Es necesario tambien asociar los datos de una tarjeta de débito válida, para esto se necesitará de:

5. ***Número de tarjeta***
6. <strong style="color: #f00">CVV</strong>
7. ***Fecha de vencimiento***
8. ***Confirmación por correo electrónico***

Finalmente, se le pedirá al usuario crear una **clave digital** para los inicios de sesión posteriores.

### Inicio de sesión

---

Solo necesitarás de tu **clave digital** para acceder a todas las funciones del programa.

## Menu Principal
Una vez se haya accedido con una cuenta registrada, serás llevado al [menú principal](#menu-principal) donde dispondrás de 4 opciones:
* [Motrar saldo](#mostrar-saldo)
* [Motrar cartera digital](#mostrar-cartera-digital)
* [Administrar deudas](#administrar-deudas)
* [Historial de pagos](#historial-de-pagos)
* [Nuestros asesores digitales](#asesores-digitales)
### Mostrar saldo

---

Muestra la cantidad de dinero disponible en la tarjeta de débito registrada del usuario.

### Mostrar cartera digital

---

Muestra la cantidad de puntos disponibles en la cartera digital para realizar descuentos con cada cancelación de una deuda del usuario.

#### Mostrar saldo

Se muestra el saldo ahorrado dentro de la cartera digital.

#### Canjear saldo

Una vez que el deudor finalice de pagar la deuda completa, esta opción se activará mostrando opciones de productos, de lo contrario, se mostrará un mensaje con texto "Opción no disponible". Se activará una vez que termine de cancelar la deuda completa.

La lista de productos en una tabla.

| Producto | Precio | Proveedor | Descripción |
|---|---|---|---|
|P1 |S/. 210.00| TOTTUS | [Descripción] |
|P2|S/. 175.23| METRO | [Descripción] |
|...|...|...|...|

Una vez que el cliente haya elegido el producto, se le solicitará su dirección, numero de celular, DNI. Para realizar envío a domicilio. Se le cobrará un pequeño monto por envío.

### Administrar deudas

---

Funcionalidad principal de nuestro programa, al seleccionarse mostrará todas las deudas con la información básica correspondiente a cada una. 

| Nombre de la deuda | Monto de la deuda |...|
|---|---|---|
|Nombre 😊|S/. 210.00|...|
|Nombre 😂|S/. 175.23|...|
|...|...|...|

---

### (Inciso) Opciones de filtros para el muestreo de deudas
También es posible que el usuario desee filtrar las deudas (ya sea por fecha, monto, entidad, etc), para esto ofrecemos una manera simple y sencilla de lograrlo.

<!--Definición de parámetros-->
---

Después de que se impriman las deudas, se mostrará un menú adicional para poder seleccionar la deuda que se desea gestionar. Las acciones a realizar con la deuda seleccionada se muestran a continuación:

* [Pagar deuda](#pagar-deuda)
* [Visualizar deuda completa](#visualizar-deuda-completa)

#### Pagar deuda

---

Submenú donde se muestran los datos básicos de la deuda a cancelar además del envio de un correo de verificación para asegurarnos de la autenticidad del usuario. **Se aplicará un descuento si el pago se realiza antes de la fecha límite.**

#### Visualizar deuda completa 

---

Muestra un submenú de solo lectura con la información detallada de la deuda seleccionada.

### Historial de pagos

---

Muestra en una tabla **las deudas canceladas y las cuotas ya pagadas de las deudas sin cancelar**, dandote la opción de [filtrar](#inciso-opciones-de-filtros-para-el-muestreo-de-deudas) las deudas y mostrar las [boleta de pago](#boletas-de-pago) de la que selecciones.

#### Boletas de pago

---

Puedes **seleccionar una boleta de pago específica de cualquier importe a una deuda**, imprimiendo los detalles en la pantalla y presentándote las siguientes opciones a elegir:

* Enviar una copia al correo electrónico registrado
* Imprimir la boleta de pago seleccionada

### Asesores digitales

---

Se muestra una lista con la información de nuestros asesores, **permitiendo a los usuarios interactuar con ellos para resolver las dudas que tengan respecto a las funcionalidades del programa.** Se puede puntuar el nivel de atención de estos asesores como feedback para nosotros.

#### ¿Desea contactar un asesor?

---

Se debe ingresar el numero asociado al asesor en el menú mostrado para verificar su disponibilidad, en caso de que no este disponible se notificará a un asesor que esté libre.
