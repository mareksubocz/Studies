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
        checkString(kod, 'Podaj kod!') &&
        checkString(ulica, 'Podaj ulicę!') &&
        checkString(miasto, 'Podaj miasto!'))
        return true;
    else return false;
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