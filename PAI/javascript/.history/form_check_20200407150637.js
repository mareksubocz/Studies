function isEmpty(str) {
    return str.length == 0;
}

function validate(formularz) {
    if (isEmpty(formularz.elements["f_imie"].value)) {
        alert('Podaj imię!');
        return false;
    }
    return true;
}

function isWhiteSpaceOrEmpty(str) {
    return /^[\s\t\r\n]*$/.test(str);
}