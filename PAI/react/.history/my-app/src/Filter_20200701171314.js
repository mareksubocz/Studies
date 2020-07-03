import React from 'react';

function Filter(props) {
    return ( 
        <div className="filter">
            <input type = "checkbox" id="filter" name="filter" checked={props.filtered} onChange={() => props.onFilterChange}/>
            <label for="filter"> hide completed</label>
        </div>
    );
}

export default Filter
