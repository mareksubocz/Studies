function isEmpty(str) {
    return str.length == 0;
}

function validate(form) {
    let imie = form.elements["f_imie"];
    let nazwisko = form.elements["f_nazwisko"].value;
    let kod = form.elements["f_kod"].value;
    let ulica = form.elements["f_ulica"].value;
    let miasto = form.elements["f_miasto"].value;
    let email = form.elements["f_email"].value;
    if (checkStringAndFocus(imie, 'Podaj imię!') &&
        checkStringAndFocus(nazwisko, 'Podaj nazwisko!') &&
        checkStringAndFocus(kod, 'Podaj kod!') &&
        checkStringAndFocus(ulica, 'Podaj ulicę!') &&
        checkStringAndFocus(miasto, 'Podaj miasto!') &&
        checkEmailAndFocus(email))
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

function checkEmail(str) {
    let email = /^[a-zA-Z_0-9\.]+@[a-zA-Z_0-9\.]+\.[a-zA-Z][a-zA-Z]+$/;
    if (email.test(str))
        return true;
    else {
        alert("Podaj właściwy e-mail");
        return false;
    }
}

function checkStringAndFocus(obj, msg) {
    let str = obj.value;
    let errorFieldName = "e_" + obj.name.substr(2, obj.name.length);
    if (isWhiteSpaceOrEmpty(str)) {
        document.getElementById(errorFieldName).innerHTML = msg;
        obj.focus();
        return false;
    } else {
        return true;
    }
}

function checkEmailAndFocus(obj, msg) {
    let str = obj.value;
    let errorFieldName = "e_" + obj.name.substr(2, obj.name.length);
    if (checkEmail(str)) {
        document.getElementById(errorFieldName).innerHTML = msg;
        obj.focus();
        return false;
    } else {
        return true;
    }
}