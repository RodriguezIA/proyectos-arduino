const socket = io();

socket.on('lumens', function (data) {
    console.log(data);
   let lun = document.getElementById("lum");
   lun.innerHTML = `${data} Lums`;


    let inf = document.getElementById("info");
    if (data < 10 && data > 7) {
        inf.innerHTML = "se prendio un led";
    } else if (data < 7 && data > 4) {
        inf.innerHTML = "se prendio dos leds";
    } else if (data < 4) {
        inf.innerHTML = "se prendio tres leds";
    } else if (data > 10) {
        inf.innerHTML = "leds apagados";
    }
});
