function isEmpty(str) {
    return str.length == 0;
}

function validate(form) {
    var imie = form.elements["f_imie"].value;
    var nazwisko = form.elements["f_nazwisko"].value;
    var kod = form.elements["f_kod"].value;
    var ulica = form.elements["f_ulica"].value;
    var miasto = form.elements["f_miasto"].value;
    if (checkString(imie, 'Podaj imię!') &&
        checkString(nazwisko, 'Podaj nazwisko!') &&
        return checkString(kod, 'Podaj kod!') &&
            return checkString(ulica, 'Podaj ulicę!') &&
                return checkString(miasto, 'Podaj miasto!'))
        return true;
}

function isWhiteSpaceOrEmpty(str) {
    return /^[\s\t\r\n]*$/.test(str);
}

function checkString(str, msg) {
    if (isWhiteSpaceOrEmpty(str)) {
        alert(msg);
        return false;
    }
    return true;
}