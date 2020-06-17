function isEmpty(str) {
    return str.length == 0;
}

function validate(form) {
    var imie = form.elements["f_imie"].value;
    var nazwisko = form.elements["f_imie"].value;
    var kod = form.elements["f_imie"].value;
    var ulica = form.elements["f_imie"].value;
    var miasto = form.elements["f_imie"].value;
    if (isWhiteSpaceOrEmpty(imie)) {
        alert('Podaj imię!');
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