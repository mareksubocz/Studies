import React from 'react';

function Task(props) {

    function zaliczone(){
        this.setState({
            zaliczone: true
        });
    }

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key} checked={props.done} onChange={zaliczone}/>
            <label for={props.key}> {props.text}</label>
        </div>
        
    );
}

export default Task