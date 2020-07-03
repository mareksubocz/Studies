import React from 'react';

function Filter() {
    return ( 
        <div className="filter">
            <input type = "checkbox" id="filter" name="filter"/>
            <label for="filter"> hide completed</label>
        </div>
    );
}

export default Filter
