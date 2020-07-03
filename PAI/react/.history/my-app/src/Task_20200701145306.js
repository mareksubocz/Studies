import React from 'react';

function Task(props) {

    const [zaliczone, setZaliczone] = useState(0);

    function zaliczone(){
        this.setState({
            zaliczone: true
        });
    }

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key} checked={props.done} onChange={state.zaliczone}/>
            <label for={props.key}> {props.text}</label>
        </div>
        
    );
}

export default Task