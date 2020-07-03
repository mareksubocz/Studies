import React from 'react';

function Task(props) {
    return ( 
        <div className="task" style={{visibility: (props.filter && props.zaliczone)? "hidden" : "visible"}}>
            <input type = "checkbox" id={props.id} name={props.id} checked={props.zaliczone} onChange={() => props.onCheckboxChange(props.id)}/>
            <label for={props.id} style={{textDecoration: props.zaliczone ? 'line-through' : 'none'}}> {props.text}</label>
        </div>  
    );
}

export default Task