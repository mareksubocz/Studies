import React from 'react';

function Task(props) {
    return ( 
        <div className="task">
            <input type = "checkbox" id="ajdi" name="ajdi"/>
            <label for="ajdi"> {props.text}</label>
        </div>
        
    );
}

export default Task