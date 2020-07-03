import React, {useState} from 'react';

function Task(props) {

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key} checked={zaliczone} onChange={props.onCheckboxCange}/>
            <label for={props.key} style={{textDecoration: zaliczone ? 'line-through' : 'none'}}> {props.text}</label>
        </div>
        
    );
}

export default Task