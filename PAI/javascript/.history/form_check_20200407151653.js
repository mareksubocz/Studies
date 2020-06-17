function isEmpty(str) {
    return str.length == 0;
}

function validate(form) {
    var imie = form.elements["f_imie"].value;
    var nazwisko = form.elements["f_nazwisko"].value;
    var kod = form.elements["f_kod"].value;
    var ulica = form.elements["f_ulica"].value;
    var miasto = form.elements["f_miasto"].value;
    if (isWhiteSpaceOrEmpty(imie)) {
        alert('Podaj imię!');
        return false;
    } else if (isWhiteSpaceOrEmpty(nazwisko)) {
        alert('Podaj nazwisko!');
        return false;
    } else if (isWhiteSpaceOrEmpty(kod)) {
        alert('Podaj kod!');
        return false;
    } else if (isWhiteSpaceOrEmpty(ulica)) {
        alert('Podaj ulicę!');
        return false;
    } else if (isWhiteSpaceOrEmpty(miasto)) {
        alert('Podaj miasto!');
        return false;
    }
    return true;
}

function isWhiteSpaceOrEmpty(str) {
    return /^[\s\t\r\n]*$/.test(str);
}

function checkString(str, msg) {
    if (validate(str)) {
        alert(msg);
        return false;
    }
    return true;
}