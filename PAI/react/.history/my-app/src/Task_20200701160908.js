import React from 'react';

function Task(props) {

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key} checked={props.zaliczone} onChange={props.onCheckboxChange(props.key)}/>
            <label for={props.key} style={{textDecoration: props.zaliczone ? 'line-through' : 'none'}}> {props.text}</label>
        </div>
        
    );
}

export default Task