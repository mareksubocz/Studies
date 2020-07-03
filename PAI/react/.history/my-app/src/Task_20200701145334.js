import React from 'react';

function Task(props) {

    const [zaliczone, setZaliczone] = useState(0);

    function handleChange(){
        this.setState({
            zaliczone: true
        });
    }

    return ( 
        <div className="task">
            <input type = "checkbox" id={props.key} name={props.key} checked={props.done} onChange={handleChange}/>
            <label for={props.key}> {props.text}</label>
        </div>
        
    );
}

export default Task