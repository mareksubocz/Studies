function validate(form) {
    let imie = form.elements["f_imie"];
    let nazwisko = form.elements["f_nazwisko"];
    let kod = form.elements["f_kod"];
    let ulica = form.elements["f_ulica"];
    let miasto = form.elements["f_miasto"];
    let email = form.elements["f_email"];
    if (checkAndFocus(imie, 'Podaj imię!', isWhiteSpaceOrEmpty) &&
        checkAndFocus(nazwisko, 'Podaj nazwisko!', isWhiteSpaceOrEmpty) &&
        checkAndFocus(kod, 'Podaj kod!', isWhiteSpaceOrEmpty) &&
        checkAndFocus(ulica, 'Podaj ulicę!', isWhiteSpaceOrEmpty) &&
        checkAndFocus(miasto, 'Podaj miasto!', isWhiteSpaceOrEmpty) &&
        checkAndFocus(email, 'Podaj właściwy email!', isEmailInvalid))
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

function checkAndFocus(obj, msg, func) {
    let str = obj.value;
    let errorFieldName = "e_" + obj.name.substr(2, obj.name.length);
    if (func(str)) {
        document.getElementById(errorFieldName).innerHTML = msg;
        obj.focus();
        return false;
    } else {
        document.getElementById(errorFieldName).innerHTML = '';
        return true;
    }
}

function showElement(e) {
    document.getElementById(e).style.visibility = 'visible';
}

function hideElement(e) {
    document.getElementById(e).style.visibility = 'hidden';
}

function alterRows(i, e) {
    alert('jetstem')
    if (e) {
        if (i % 2 == 1) {
            e.setAttribute("style", "background-color: Aqua;");
        }
        e = e.nextSibling;
        while (e && e.nodeType != 1) {
            e = e.nextSibling;
        }
        alterRows(++i, e);
    }
}