function isEmpty(str) {
    return str.length == 0;
}

function validate(form) {
    let imie = form.elements["f_imie"];
    let nazwisko = form.elements["f_nazwisko"];
    let kod = form.elements["f_kod"];
    let ulica = form.elements["f_ulica"];
    let miasto = form.elements["f_miasto"];
    let email = form.elements["f_email"];
    if (checkStringAndFocus(imie, 'Podaj imię!') &&
        checkStringAndFocus(nazwisko, 'Podaj nazwisko!') &&
        checkStringAndFocus(kod, 'Podaj kod!') &&
        checkStringAndFocus(ulica, 'Podaj ulicę!') &&
        checkStringAndFocus(miasto, 'Podaj miasto!') &&
        checkEmailAndFocus(email, 'Podaj właściwy email!'))
        return true;
    else return false;
}

function isWhiteSpaceOrEmpty(str) {
    return /^[\s\t\r\n]*$/.test(str);
}

function isEmailInvalid(str) {
    let email = /^[a-zA-Z_0-9\.]+@[a-zA-Z_0-9\.]+\.[a-zA-Z][a-zA-Z]+$/;
    return !email.test(str);
}

function checkStringAndFocus(obj, msg) {
    let str = obj.value;
    let errorFieldName = "e_" + obj.name.substr(2, obj.name.length);
    if (isWhiteSpaceOrEmpty(str)) {
        document.getElementById(errorFieldName).innerHTML = msg;
        obj.focus();
        return false;
    } else {
        document.getElementById(errorFieldName).innerHTML = '';
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
        document.getElementById(errorFieldName).innerHTML = '';
        return true;
    }
}

function checkAndFocus(obj, msg, func) {

}