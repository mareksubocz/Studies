function isEmpty(str) {
    return str.length == 0;
}

function validate(formularz) {
    alert('cos')
    if (isEmpty(formularz.elements["f_imie"].value)) {
        alert('Podaj imię!');
        return false;
    }
    alert('true');
    return true;
}