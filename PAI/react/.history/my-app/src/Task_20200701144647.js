import React from 'react';

function Task(props) {

    function zaliczone(){
        this.setState({
            zaliczone: true
        });
    }

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key} checked={this.state.done} onChange={this.zaliczone}/>
            <label for={props.key}> {props.text}</label>
        </div>
        
    );
}

export default Task