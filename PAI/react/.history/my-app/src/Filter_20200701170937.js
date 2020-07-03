import React from 'react';

function Filter(props) {
    return ( 
        <div className="filter">
            <input type = "checkbox" id="filter" name="filter" onChange={() => props.onFilterChanged}/>
            <label for="filter"> hide completed</label>
        </div>
    );
}

export default Filter
