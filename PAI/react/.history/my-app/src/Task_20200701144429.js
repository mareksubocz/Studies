import React from 'react';

function Task(props) {

    // function zaliczone(){
    //     props.
    // }

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key}/>
            <label for={props.key}> {props.text}</label>
        </div>
        
    );
}

export default Task