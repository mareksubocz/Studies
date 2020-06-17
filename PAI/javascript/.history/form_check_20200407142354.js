function isEmpty(str) {
    return str.length == 0;
}

function validate(formularz) {
    isEmpty(formularz.elements["f_imie"].value);
}