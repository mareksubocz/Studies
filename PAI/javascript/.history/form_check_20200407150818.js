function isEmpty(str) {
    return str.length == 0;
}

function validate(formularz) {
    var imie = isEmpty(formularz.elements["f_imie"].value);
    if (isWhiteSpaceOrEmpty(imie)) {
        alert('Podaj imię!');
        return false;
    }
    return true;
}

function isWhiteSpaceOrEmpty(str) {
    return /^[\s\t\r\n]*$/.test(str);
}